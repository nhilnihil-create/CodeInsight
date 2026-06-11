#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

int N;
ll arr[200001];

int main() {
    cin>>N;
    cin>>arr[0];
    for(int i=1;i<N;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }

    ll ret = INT_MAX;
    int left=0;
    int mid=1;
    int right=2;
    for(;mid<N-2;mid++){

        while(abs(arr[left]-(arr[mid]-arr[left])) >= abs(arr[left+1]-(arr[mid]-arr[left+1])))
            left++;

        while(abs((arr[N-1]-arr[right])-(arr[right]-arr[mid])) >= abs((arr[N-1]-arr[right+1])-(arr[right+1]-arr[mid])))
            right++;

        
        ll l1 = arr[left];
        ll l2 = arr[mid]-arr[left];
        ll r1 = arr[right]-arr[mid];
        ll r2 = arr[N-1]-arr[right];

        ll minval = min(min(l1,l2),min(r1,r2));
        ll maxval = max(max(l1,l2),max(r1,r2));

        ret = min(ret, maxval-minval);
    }
    cout<<ret;
    
}