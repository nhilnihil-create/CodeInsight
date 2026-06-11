#include "iostream"
#include "vector"
using namespace std;
int main()
{
    int r,d,x200;
    cin>>r>>d>>x200;
    
    int result[11];
    result[0]=x200;
    
    for(int i=1;i<=10;i++)
    {
        result[i]=result[i-1]*r-d;
        cout<<result[i]<<endl;
    }
    
    
}
