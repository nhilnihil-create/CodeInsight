#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main (){
    /*
    int N, K;
    cin >> N >> K;
    vector <int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];
    if(K-N==0){
        cout << 1 << endl;
    }else if((K-N)%(K-1) == 0){
        cout << (N-K)/(K-1)+1 << endl;
    }else{
        cout << (N-K)/(K-1)+2 << endl;
    }
    */
   int n,k; cin >> n >> k;
   vector<int> a(n); 
   if((n-k)%(k-1) == 0){
       cout << (n-k)/(k-1)+1 << endl;
   }else{
       cout << (n-k)/(k-1)+2 << endl;
   }
}