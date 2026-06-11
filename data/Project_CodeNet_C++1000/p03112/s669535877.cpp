#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define PUTS(x) cout << (x) << endl;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define ALL(v) (v).begin(), (v).end()
#define INF 1e12

enum Type {
    A,
    B
};

// 実座標での物体位置
struct Coordinate {
    Type type;
    Int real;
};

// 物体の「間」を表す
struct Space {
    Int nearestA1; // それより左の最近のAの圧縮座標（非存在時は-1）
    Int nearestB1; // それより左の最近のBの圧縮座標（非存在時は-1）
    Int nearestA2; // それより右の最近のAの圧縮座標（非存在時は-1）
    Int nearestB2; // それより右の最近のBの圧縮座標（非存在時は-1）
};

int main() {
    Int a, b, Q;
    cin >> a >> b >> Q;
    auto values = vector<Int>(); // 登場する全実座標値
    auto coordinates = vector<Coordinate>();
    rep(i, a) {
        Int s;
        cin >> s;
        coordinates.push_back(Coordinate{A, s});
        values.push_back(s);
    }
    rep(i, b) {
        Int t;
        cin >> t;
        coordinates.push_back(Coordinate{B, t});
        values.push_back(t);
    }

    // 登場した実座標値の順にソート
    sort(ALL(coordinates), [&](const auto &a, const auto &b) {
        return a.real < b.real;
    });
    sort(ALL(values));

    // 「間」を表す列（最小より左: i=0, 最大より右: i=a+b）
    auto spaces = vector<Space>(a + b + 1, Space{-1, -1, -1, -1});
    // 「間」のインデックスを求める関数（ソート済み実座標列の前から何番目かを二分法で取得，非登場の値に対しては「それ以上のやつで最小のやつのインデックス値（それ以上のものがないときは last index + 1 の値）を返す）
    auto realToRel = [&](Int realValue) -> Int {
        return lower_bound(ALL(values), realValue) - values.begin();
    };

    // 左から走査
    Int nearestA = -1;
    Int nearestB = -1;
    for (Int i = 0; i < a + b; i++) {
        auto coordinate = coordinates[i];
        switch (coordinate.type) {
        case A:
            nearestA = i;
            break;
        case B:
            nearestB = i;
            break;
        }
        // index が1つ次の「間」の最近接情報を更新
        spaces[i + 1].nearestA1 = nearestA;
        spaces[i + 1].nearestB1 = nearestB;
    }

    // 右から走査
    nearestA = -1;
    nearestB = -1;
    for (Int i = a + b - 1; i >= 0; i--) {
        auto coordinate = coordinates[i];
        switch (coordinate.type) {
        case A:
            nearestA = i;
            break;
        case B:
            nearestB = i;
            break;
        }
        spaces[i].nearestA2 = nearestA;
        spaces[i].nearestB2 = nearestB;
    }

    rep(i, Q) {
        Int start;
        cin >> start;
        Int spaceIndex = realToRel(start); // この実座標が属する「間」のインデックス
        auto space = spaces[spaceIndex];
        auto a1 = space.nearestA1;
        auto b1 = space.nearestB1;
        auto a2 = space.nearestA2;
        auto b2 = space.nearestB2;

        // start → x → y と進むときの距離
        auto test = [&](Int x, Int y) -> Int {
            if (x < 0 || y < 0) {
                return INF;
            }
            auto xReal = coordinates[x].real;
            auto yReal = coordinates[y].real;
            auto v = abs(start - xReal) + abs(xReal - yReal);
            //printf("%lld -> %lld -> %lld = %lld\n", start, xReal, yReal, v);
            return v;
        };

        Int ans = INF;
        //printf("spaceIndex=%lld, a1=%lld, b1=%lld, a2=%lld, b2=%lld\n", spaceIndex, a1, b1, a2, b2);
        ans = min(ans, test(a1, b1));
        ans = min(ans, test(a1, b2));
        ans = min(ans, test(a2, b1));
        ans = min(ans, test(a2, b2));
        ans = min(ans, test(b1, a1));
        ans = min(ans, test(b1, a2));
        ans = min(ans, test(b2, a1));
        ans = min(ans, test(b2, a2));
        PUTS(ans)
    }
}
