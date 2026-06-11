#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    float total=0.0;
    for(int i=0;i<n;i++)
    {
        float f;
        string s;
        cin>>f>>s;
        if(s[0]=='J'){
            total+=f;
        }
        else
        {
            total+=(f*380000.0);
        }
    }
    cout<<total;
}