#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
int main(){
    double N;
    cin>>N;
    cout << fixed << setprecision(10);//double型を今後小数第10位まで出力 
    for(int i=1;i<=3500;i++){
        for(int j=1;j<=3500;j++){
            double h = i;
            double n = j;
            double w =1/(4/N-1/h-1/n);
            if(abs(w-round(w))<=0.000000001 && w>0 && w<=3500){
                cout<<i<<" "<<j<<" "<<int64_t(round(w))<<endl;
                return 0;
            }
        }
    }
}