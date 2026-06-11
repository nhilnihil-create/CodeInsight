#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int n; 
    cin>>n;
    unordered_set<int>ump;
    int index=1;
    while(ump.find(n)==ump.end()){
        ump.insert(n);
        if(n%2==0){
            n/=2;
        }
        else{
            n=3*n+1;
        }
        index++;
    }
    cout<<index;
}