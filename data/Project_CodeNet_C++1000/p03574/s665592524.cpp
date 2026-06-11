#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
    fast;
    int h,w;
    cin>>h>>w;
    char ans[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>ans[i][j];
    int arr[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
           arr[i][j]=0;
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++){
            if(ans[i][j]=='#'){
                if(i-1>=0)
                {
                    arr[i-1][j]++;
                    if(j+1<w)
                        arr[i-1][j+1]++;
                    if(j-1>=0)
                        arr[i-1][j-1]++;
                }
                if(j-1>=0)
                    arr[i][j-1]++;
                if(i+1<h)
                {
                    arr[i+1][j]++;
                    if(j+1<w)
                        arr[i+1][j+1]++;
                    if(j-1>=0)
                        arr[i+1][j-1]++;
                }
                if(j+1<w)
                    arr[i][j+1]++;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
        	if(ans[i][j]=='.')
	            cout<<arr[i][j];
	        else
	        	cout<<'#';
            cout<<endl;
    }
    

    return 0;
}