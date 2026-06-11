#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
map<int,int64_t> p;
//O(√n)
//素因数分解
void fl(int64_t n){
    if(n==1){
        return ;
    }
    int tmp = n;
    while(tmp%2==0 ){
        tmp /= 2;
        p[2]++;
    }
    for(int i=3;i*i<=tmp;i++){
        while(tmp % i ==0){
            tmp /= i;
            p[i]++;
        }
    }
    if(tmp!=1){//まだ割り切れてない場合、√Nまでは見てるから
        p[tmp]++;
    }
}
int main(){
    int n;
    cin>>n;
    if(n<=9){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        fl(i);
    }
    int s=p.size();
    int p75,p3,p25,p5,p15;
    p75=0;
    p3=0;
    p25=0;
    p5=0;
    p15=0;
    for(auto c:p){
        //cout<<c.first<<" "<<c.second<<endl;
        int sh = c.second;//肩
        if(sh>=74){
            p75++;
        }
        if(sh>=24){
            p25++;
        }
        if(sh>=14){
            p15++;
        }
        if(sh>=4){
            p5++;
        }
        if(sh>=2){
            p3++;
        }
    }
    //cout<<p75<<" "<<p25<<" "<<p15<<" "<<p5<<" "<<p3<<endl;
    cout<<p75+p25*(p3-1)+(p5-1)*p15+(p3-2)*p5*(p5-1)/2<<endl;
    //約数75個 => x^74,x^24*y^2, x^4*y^14, x^2*y^4*z^4の場合 
}