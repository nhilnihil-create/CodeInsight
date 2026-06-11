#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int main()
{
    string N;
    cin>>N;
    int sum=0;
    int num = stoi(N);
    for(int i=0;i<N.size();i++)
    {
        sum+=(N[i]-'0');
    }
    if(num%sum==0)
    {
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}

