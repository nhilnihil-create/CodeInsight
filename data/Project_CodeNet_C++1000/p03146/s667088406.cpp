#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> a;
    int s, t;
    cin>>s;
    a.push_back(s);
    t=s;
    for (int i = 0; i < 1000000; i++)
    {
        if (t%2==0)
        {
            t=t/2;          
        }
        else
        {
            t=3*t + 1;
        }
        if (find(a.begin(), a.end(), t) != a.end())
        {
            cout<<i+2;
            break;
        }
        a.push_back(t);
        
        
        
    }
    
    
    
}