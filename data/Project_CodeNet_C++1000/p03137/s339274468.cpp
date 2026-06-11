#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> x(M);
    vector<int> a(M);
    for(int i=0;i<M;i++){
      cin>>x[i];
    }
    sort(x.begin(),x.end());
    for(int i=1;i<M;i++){
      a[i-1]=x[i]-x[i-1];
    }
    int w=0;
    sort(a.rbegin(),a.rend());
    for(int i=N-1;i<M-1;i++){
      w+=a[i];
    }
      cout<<w<<endl;
    return 0;
}


