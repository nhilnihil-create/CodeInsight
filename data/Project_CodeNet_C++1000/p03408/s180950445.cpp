#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define coYes cout << "Yes" << endl
#define coYES cout << "YES" << endl
#define coyes cout << "yes" << endl
#define coNo cout << "No" << endl
#define coNO cout << "NO" << endl
#define cono cout << "no" << endl
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){ //最大公約数
    if(a%b == 0){
        return b;
    }else{
    return gcd(b, a%b);
    }
}

int main(){
    int n,m,count=0;
    cin >> n ;
    vector<string> s(n);
    rep0(i,n){
        cin >> s[i];
    }
    cin >> m;
    vector<string> t(m);
    rep0(i,m){
        cin >> t[i];
    }
    rep0(i,n){
        int c=0;
        rep0(j,n){
            if(s[i]==s[j]) c++;
        }
        rep0(j,m){
            if(s[i]==t[j]) c--;
        }
        count=max(c,count);
    }
    cout << count << endl;
    return 0;
}