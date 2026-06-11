#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for(auto i:s)sum+=i-'0';
    cout << max(s[0]-'0'+9*(n-1)-1,sum) << endl;
    return 0;
}