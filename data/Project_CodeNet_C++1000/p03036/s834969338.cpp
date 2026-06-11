#include<iostream>
#include<vector>

using namespace std;

int main() 
{
    int r,D,x2k;
    cin>>r>>D>>x2k;

    vector<ulong>xs;
    xs.push_back(x2k);
    for(int i=1;i<11;++i)
    {
        xs.push_back((r*xs[i-1])-D);
    }

    for(int i=1;i<11;++i)
    {
        cout<<xs[i]<<endl;
    }

    return 0;
    
}