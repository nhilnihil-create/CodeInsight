#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    string s,t ;
    cin >> s >> t;
    sort(all(s));
    sort(all(t));
    reverse(all(t));
    if(s<t)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}