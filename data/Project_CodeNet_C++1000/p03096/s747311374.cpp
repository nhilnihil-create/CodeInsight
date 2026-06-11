#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int pt[1000000], last[1000000];
int main(){
    int num;
    cin >> num;
    pt[0]=1;
    for(int i=1,x;i<=num;i++){
        cin>>x;
        pt[i]=pt[i-1];
        if(last[x]&&last[x]!=i-1)
            pt[i]+=pt[last[x]];
        last[x]=i;
        pt[i]%=1000000007;
    }
    cout<<pt[num];
    return 0;
}
