#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,sub;
    cin>>s;
    int digit,arr[10],n=s.length();
    for(int i=0;i<n-1;i++){
        sub=s.substr(i,3);
        digit=(sub[0]-'0')*100+(sub[1]-'0')*10+(sub[2]-'0');
        arr[i]=abs(digit-753);
    }
    sort(arr,arr+n-2);
    cout<<arr[0];
    return 0;
}
