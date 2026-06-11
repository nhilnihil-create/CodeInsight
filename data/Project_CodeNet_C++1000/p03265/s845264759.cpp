#include<iostream>
using namespace std;
int main(){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int w=x2-x1;
    int h=y2-y1;
    cout<<x2-h<<" "<<y2+w<<" ";
    cout<<x1-h<<" "<<y1+w;
}