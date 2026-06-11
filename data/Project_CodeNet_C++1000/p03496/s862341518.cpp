#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
int main(void) {
    int N,maxa = 0;
    int code = 0;
    int pos = 0;
    cin >> N;

    vector<int> a(N);
//    random_device rd;
//    mt19937 mt(rd());
//    uniform_int_distribution<int> d(-1000000,1000000);
    for(int i=0;i<N;i++) {
//        a[i] = d(mt);
        cin >> a[i];
        if(maxa < abs(a[i])) {
            maxa = abs(a[i]);
            code = a[i] > 0 ? 1 : -1;
            pos = i;
        }
    }

    // ＋かーに統一してしまう。
    // +の場合左から前を足していく
    // -の場合右から前を足していく
    if(code == 0) {
        cout << "0\n";
    } else if(code > 0) {
        vector<P> ans;
        for(int i=0;i<N;i++) {
            if(i==pos) continue;
            if(a[i] < 0) {
                a[i]+= a[pos];
                ans.push_back(make_pair(pos+1,i+1));
            }
        }

        for(int i=1;i<N;i++) {
            if(a[i-1] > a[i]) {
                ans.push_back(make_pair(i,i+1));
                a[i] += a[i-1];
            }
        }

        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    } else {
        vector<P> ans;
        for(int i=0;i<N;i++) {
            if(i==pos) continue;
            if(a[i] > 0) {
                a[i]+= a[pos];
                ans.push_back(make_pair(pos+1,i+1));
            }
        }

        for(int i=N-2;i>=0;i--) {
            if(a[i+1] < a[i]) {
                ans.push_back(make_pair(i+2,i+1));
                a[i] += a[i+1];
            }
        }

        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}
