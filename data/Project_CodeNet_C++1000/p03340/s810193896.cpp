#include <iostream>
#define int long long
using namespace std;

signed main(){
    int n, A[200000]={0};
    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];
    int right=0;
    int sum=0;
    int ans=0;
    for(int left=0;left<n;left++){
        while(right<n&&((sum+A[right])==(sum ^ A[right]))){
            sum += A[right];
            right++;
        }
        ans += right-left;
        if(left==right) right++;
        else sum -= A[left];
    }
    cout << ans << endl;
    return 0;
}