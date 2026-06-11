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
    int n,m,x,temp;
    bool flag=false;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep0(i,m){
        cin >> a[i];
        if(x<a[i]){
            temp=i;
            break;
        }
    }
    int q=0,w=0;
    rep0(i,temp)
        q++;
    rep0(i,m-temp)
        w++;
    cout << min(q,w) << endl;
    return 0;
}