#include<iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int b=0,c=0;
    for(int i = 0; i<a.size();i++){
        if(a[i]== '+') b++;
        if(a[i]== '-') c++;
    }
    int k = b-c;
    cout<<k;
    return 0;
}
