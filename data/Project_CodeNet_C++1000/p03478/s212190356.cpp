#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(n);++i)
#define repeq(i,a,n) for(int i=a;i<=(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

/*
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int tmp,tmp1,tmp2,tmp3,tmp4,tmp5=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i<10){
            if(i>=a && i<=b){
                sum+=i;
            }
        }else if(10<=i && i<100){
            tmp1=i%10;
            tmp2=(i/10)%10;
            tmp=tmp1+tmp2;
            if(tmp>=a && tmp<=b){
                sum+=i;
            }
        }else if(100<=i && i<1000){
            tmp1=i%10;
            tmp2=(i/10)%10;
            tmp3=(i/100)%10;
            tmp=tmp1+tmp2+tmp3;
             if(tmp>=a && tmp<=b){
                sum+=i;
            }
        }else if(1000<=i && i<10000){
            tmp1=i%10;
            tmp2=(i/10)%10;
            tmp3=(i/100)%10;
            tmp4=(i/1000)%10;
            tmp=tmp1+tmp2+tmp3+tmp4;
             if(tmp>=a && tmp<=b){
                sum+=i;
            }
        }else if(10000<=i && i<100000){
            tmp1=i%10;
            tmp2=(i/10)%10;
            tmp3=(i/100)%10;
            tmp4=(i/1000)%10;
            tmp5=(i/10000)%10;
            tmp=tmp1+tmp2+tmp3+tmp4+tmp5;
             if(tmp>=a && tmp<=b){
                sum+=i;
            }
        }
        //cout << "sum:" << sum <<endl;
    }

    cout << sum << endl;
    return 0;
}*/

int main(){
    int n,a,b;
    cin >> n >> a >> b;

    int sum=0;
    int total=0;
    int tmp=0;
    repeq(i,1,n){
        sum=0;
        tmp=i;
        while(tmp>0){
            sum+=tmp%10;
            tmp/=10;
        }
        if(a<=sum && sum<=b){
            total+=i;
        }
    }

    cout << total << endl;
    return 0;
}