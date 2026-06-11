#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int countre=0;
    for(int i=1;i<n;i++){
        if(s.at(i)=='E') countre++;
    }
    int min=countre;
    for(int i=0;i<n-1;i++){
        if(s.at(i)=='W'){
            countre++;
        }
        if(s.at(i+1)=='E'){
            countre--;
        }
        if(min>countre) min=countre;
    }
    cout<<min;
}