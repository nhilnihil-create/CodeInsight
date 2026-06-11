#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
cin>>N;
string city;
int rate;
using psi = tuple<string,int,int>;
vector<psi> vec;
for(int i = 0;i<N;i++){
cin>>city>>rate;
vec.push_back(make_tuple(city,100-rate,i+1));
}
sort(vec.begin(),vec.end());
for(int i=0;i<N;i++){
tuple t =vec.at(i);
int num = get<2>(t);
cout<<num<<endl;}
}


