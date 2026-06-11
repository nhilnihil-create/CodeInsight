#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin>>n>>a;
    int x=n%500;
    (x<=a)?	cout<<"Yes" : cout<<"No";
}