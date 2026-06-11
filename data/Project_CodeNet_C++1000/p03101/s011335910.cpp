#include "iostream"
using namespace std;

int main()
{
    int h, w, a, b;
    cin>>h>>w>>a>>b;
    int x = h-a;
    int y = w-b;
    int ans = x * y;
    cout<<ans;
}