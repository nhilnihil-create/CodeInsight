#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod = 1e9+7;
const int maxn=2e5+7;

long int sad(vector<int> &arr,int b){
    long int sad_value = 0;
    for(int i=0;i<arr.size();i++){
        sad_value+=abs(arr[i] - (b+i));
    }
    return sad_value;
}

int main(){
    long lo=-1e9,hi=1e9;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    long int psad,sadv,nsad;
    while(lo<=hi){
        int b = lo + (hi-lo)/2;
        if(b==0 || b==1e9){
            sadv = sad(arr,b);
        }
        psad = sad(arr,b-1);
        sadv = sad(arr,b);
        nsad = sad(arr,b+1);
        // cout<<psad<<' '<<sadv<<' '<<nsad<<' '<<b<<endl;
        if(psad>=sadv && sadv<=nsad){
            break;
        }
        else if(psad>sadv && sadv >nsad){
            lo = b+1;
        }
        else{
            hi = b-1;
        }
    }
    cout<<sadv;
}