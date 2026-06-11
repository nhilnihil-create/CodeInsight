#include<bits/stdc++.h>
#include<iostream>
using namespace std; 
int main(){
int n;
cin>>n;
vector<tuple<string, int ,int > >res;
string s;
int p;
for(int i=0;i<n;i++){
cin>>s>>p;
res.push_back(make_tuple(s,p,i+1));
}
sort(res.begin(),res.end());
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
    if((get<0>(res[i]).compare(get<0>(res[j])))==0){
        if(get<1>(res[i])<get<1>(res[j])){
            swap(res[i],res[j]);
        }}
    }
}
for(int i=0;i<n;i++){
cout<<get<2>(res[i])<<endl;
}return 0;	
}