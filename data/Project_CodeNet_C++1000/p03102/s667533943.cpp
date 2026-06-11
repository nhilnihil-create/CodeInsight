#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;


int main() {

int n,m,c;
cin>>n>>m>>c;
int count=0;
Vec b(m),a(m);
for(int i=0;i<m;i++){
    cin>>b[i];
}
for(int i=0;i<n;i++){
    int sum=c;
    for(int j=0;j<m;j++){
        int x;
        cin>>x;
        sum+=x*b.at(j);
    }   
    if(sum>0){
        count++;
    }

}
  cout<<count<<endl;

}