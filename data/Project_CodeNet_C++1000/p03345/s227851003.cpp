#include<iostream>
#include<string>

using namespace std;

int main()
{
    long long A,B,C;cin >> A>>B>>C;
    string K;cin>>K;
    if((K[K.size()-1]-'0')%2==0)
    {
        cout << A-B<<endl;
    }else
    {
        cout << B-A<<endl;
    }
    
}