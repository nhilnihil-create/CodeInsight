#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
struct BIT{
    vector<int> bit;
    int size;
    BIT(int n):size(n), bit(n+1, 0){}
    int sum(int i){
        int s=0;
        while(i>0){
            s+=bit[i];
            i-=(i&(-i));
        }
        return s;
    }
    void add(int i, int x){
        while(i<=size){
            bit[i]+=x;
            i+=(i&(-i));
        }
    }
};
int main()
{
    int n;
    cin>>n;
    ll m=(ll)n*(ll)(n+1)/2;
    int a[100000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int x1=0, x2=1e9+1;
    while(x1!=x2){
        int x=(x1+x2+1)/2;
        int s[100001];
        s[0]=0;
        for(int i=0; i<n; i++){
            if(a[i]>=x) s[i+1]=s[i]+1;
            else s[i+1]=s[i]-1;
        }
        BIT bit(2*n+1);
        ll ct=0;
        for(int i=0; i<=n; i++){
            ct+=(ll)bit.sum(n+1+s[i]);
            bit.add(n+1+s[i], 1);
        }
        if(ct>=(m+1)/2) x1=x;
        else x2=x-1;
    }
    cout<<x1<<endl;
    return 0;
}