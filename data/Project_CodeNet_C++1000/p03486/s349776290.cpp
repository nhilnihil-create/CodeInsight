
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    string s, t;
    cin >> s >> t;
    sort(all(s)); //sはなるべく辞書順で早くなるよう昇順
    sort(all(t),greater<char>());//tはなるべく辞書順で遅くなるよう降順
    if(s<t) cout << "Yes" << endl;
    else cout <<"No" << endl;

}