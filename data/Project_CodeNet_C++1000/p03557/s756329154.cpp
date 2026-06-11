#include <bits/stdc++.h>

using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr2(i,s,n) for (int i = (n-1); i>=(int)(s);i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
const ll INF = 1001001000100010;
const ld PI = 3.14159265358979323846;



int main() {
int N;
cin>>N;
vector<ll> A(N),B(N),C(N),BtoC(N),Bsum(N);
rep(i,N){
    cin>>A[i];
}
rep(i,N){
    cin>>B[i];
}
rep(i,N){
    cin>>C[i];
}
sort(all(B));
sort(all(C));
ll key,left,right,mid,countnum=0,left2,right2,mid2;
rep(i,N){
    key=B[i];
    left=-1;right=N;
    while(true){
        mid=(left+right)/2;
        if(C[mid]==key){
            left2=mid;right2=N;
            while(true){
                mid2=(left2+right2)/2;
                if(C[mid2]==key){
                    left2=mid2;
                }
                else{
                    right2=mid2;
                }
                if(right2-left2==1){
                    BtoC[i]=N-right2;
                    break;
                    
                }


            }
            
            break;
        }
        else if(C[mid]<key){
            left=mid;
        }
        else{
            right=mid;
        }
        if(right-left==1){
            BtoC[i]=N-right;
            break;

        }
    }
}
Bsum[N-1]=BtoC[N-1];
repr(i,N-1){
    Bsum[i]=Bsum[i+1]+BtoC[i];
}
rep(i,N){
    key=A[i];
    left=-1;right=N;
    while(true){
        mid=(left+right)/2;
        if(B[mid]==key){
            left2=mid;right2=N;
            while(true){
                mid2=(left2+right2)/2;
                if(B[mid2]==key){
                    left2=mid2;
                }
                else{
                    right2=mid2;
                }
                if(right2-left2==1){
                    if(right2!=N){
                    countnum+=Bsum[right2];
                    }
            break;
                }
            }
            break;
        }
        else if(B[mid]<key){
            left=mid;
        }
        else{
            right=mid;
        }
        if(right-left==1){
            countnum+=Bsum[right];
            break;
        }
    }
}
cout<<countnum<<endl;

return 0;
}