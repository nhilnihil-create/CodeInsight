#include <numeric>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int K,counter=0;
    cin >>N>>K;
    if(N.size()==1){
    cout<<N.at(0)<<endl;}
    else{
    for(int i=0;i<N.size();i++){
    if(N.at(counter)=='1'){
    counter++;
    continue;}
    else break;}
    if(K<=counter)
    cout<<1<<endl;
    else
    cout<<N.at(counter)<<endl;}}
