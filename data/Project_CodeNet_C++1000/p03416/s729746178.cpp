#include<iostream>
#include<vector>
using namespace std;

bool checkPalindrome(int num){
    vector<int>result;
    while(num!=0)
    {
        result.push_back((num%10));
        num/=10;
    }
    for(int i=0;i<(result.size())/2;i++)
    {
        if(result[i]!=result[result.size()-1-i]){
            return false;
        }
    }
    return true;
}


int main(){
    int a,b;
    cin>>a>>b;
    int count=0;
    for(int i=a;i<=b;i++)
    {
        if(checkPalindrome(i)){
            count++;
        }
    }
    cout<<count;
}