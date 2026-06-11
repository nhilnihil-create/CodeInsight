 #include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        if(a+1 != b) a++;
        else {
            cout << "Borys" << endl;
            return 0;
        }
        if(b-1 != a) b--;
        else {
            cout << "Alice" << endl;
            return 0;
        }
    }

    cout << "Drow" << endl;

    return 0;
}