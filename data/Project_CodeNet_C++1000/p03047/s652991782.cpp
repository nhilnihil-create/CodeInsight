#include <iostream>
using namespace std;

int main() {
    long int n,k;
    cin>>n>>k;
    long int sum=n-k;
    if(sum<0)
    {
        cout<<"";
    }
    else
    {
        cout<<sum+1<<endl;
    }
    
	return 0;
}