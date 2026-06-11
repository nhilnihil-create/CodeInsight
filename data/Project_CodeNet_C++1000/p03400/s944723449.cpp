using namespace std;
#include <bits/stdc++.h>

int main()
{
    int n,d,x,a[n],b=0,c=1;
    cin>>n>>d>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b=0;
        while(b<d){
            b+=a[i];
            c++;
        }
    }
    std::cout << c+x-1 << std::endl;
    return 0;
}