#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long A[200200];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    long long L[200200], R[200200]; 
    //L:左からの累積和
    L[0]=0; R[0]=0;
    for(int i=0; i<N; i++){
        L[i+1] = L[i] + A[i];
        R[i+1] = R[i] +A[N-i-1];
    }

    const long long INF = pow(10,13); 
    long long min_dif=INF;
    int d[2];
    d[0]=0; d[1]=-1;
    long long mmin, mmax;
    mmin = INF;
    mmax = 0;
    for(int i=-1; i<N;i++){

        long long l= (L[i+1]+1)/2 ;//見つけたい値
        long long r= (R[N-i-1]+1)/2;

        long long *a = lower_bound(L,L+i+1,l);
        long long *b = lower_bound(R,R+N-i-1,r);

        for(int k=0; k<2; k++){
            for(int j=0; j<2; j++){
                long long * t=(a+d[k]);
                long long * s=(b+d[j]);
                if(  t-L >=0 && s-R>=0 ){//ダメじゃないとき
                long long P = *t; 
                long long Q = *s;
                long long T = L[i+1]-*t;
                long long S = R[N-i-1]-*s;
                long long E = max(max(P,Q), max(T,S)) - min( min(P,Q),min(T,S) );
                if(mmin > E){
//                    cout << P << T << S << Q;
//                    cout << t-L << " " << i+1 << " " << N-(s-R)-1 << endl;
                    mmin = E;
                }
                }
            }
        }
    }
    cout << mmin <<endl;
}