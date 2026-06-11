#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;






int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n-1][3];
    for(int i =0;i < n-1;i++){
        for(int j =0;j<3;j++){
            cin>>arr[i][j];;
        }
    }
    int time=0;
    for(int i =0;i<n-1;i++){
        time = arr[i][1] +  arr[i][0];
        for(int j =i+1;j<n-1;j++){
            if(time <=  arr[j][1]) {
                time = arr[j][1] + arr[j][0] ;
            }
            else{
                //bool divi=false;
                if((time - arr[j][1])%arr[j][2]==0){
                    time+=arr[j][0];
                }
                else{
                    time = (time/arr[j][2] + 1)*arr[j][2] + arr[j][0];
                }
            }
        }
        cout<<time<<endl;

    }
    cout<<0<<endl;







}




























































