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
    int n,max1=0,j=1;
    cin >> n;
    vector<int> a(n),b(n);
    rep0(i,n){
        cin >> a[i];
    }
    rep1(i,n){
        cin >> b[n-i];
    }
    while(n>0){
        int sum=0;
        rep0(i,n){
            sum+=a[i];
        }
        for(int i=0;i<j;i++){
            sum+=b[i];
        }
        n--;
        j++;
        max1=max(sum,max1);
    }
    cout << max1 << endl;
    return 0;
}