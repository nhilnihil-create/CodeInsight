#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++){    ;
int main() {
int N;
cin>>N;
vector<int>L(N);
int count=0;
int max=0;
rep(i,N)
cin>>L.at(i);
count+=L.at(i);
if(max<L.at(i)){
    max=L.at(i);
}
}
if(count-max>max){
    cout<<"Yes"<<endl;
}
else
cout<<"No"<<endl;
}