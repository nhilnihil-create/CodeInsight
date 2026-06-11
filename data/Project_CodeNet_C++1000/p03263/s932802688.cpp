#include<bits/stdc++.h>
using namespace std;
int a[505][505];
vector<pair<pair<int,int>,pair<int,int>>> ans;

int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> a[i][j];
    int i=0; int j=0;
    int solve=0;
        while(i<h && j>=0 && j<w){
            if(i==h-1 && ((i%2==0 && j==w-1) || (i%2==1 && j==0)) )break;
            else if(i%2==0 && j<w-1){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i,j+1)));
                    a[i][j+1]++;
                }
                j++;
            }
            else if(i%2==0 && j==w-1){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
                    a[i+1][j]++;
                }
                i++;
            }
            else if(i%2==1 && j>0){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i,j-1)));
                    a[i][j-1]++;
                }
                j--;
            }
            else if(i%2==1 && j==0){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
                    a[i+1][j]++;
                }
                i++;
            }            
        }
    cout << ans.size() << endl;
    for(auto u:ans)cout << u.first.first+1 << " " << u.first.second+1 << " " << u.second.first+1 <<" "<< u.second.second+1 << endl;
}