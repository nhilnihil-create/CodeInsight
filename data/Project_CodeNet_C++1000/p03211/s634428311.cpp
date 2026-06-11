#include<iostream>
#include<climits>
using namespace std;

int getMin(int a,int b,int c){
    int r=a*100+b*10+c;
    return abs(753-r);
}

int main(){
    string s;
    cin>>s;
    int min=INT_MAX;
    for(int i=0;i<s.size()-2;i++)
    {
        int k=getMin(s[i]-'0',s[i+1]-'0',s[i+2]-'0');
        if(k<min){
            min=k;
        }
    }
    cout<<min;
}