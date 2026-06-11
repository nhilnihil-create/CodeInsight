#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,x,y,h;
    cin>>n;
    std::vector<vector<pair<long long int,long long int>>> vec(101,vector<pair<long long int,long long int>>(101));
    std::vector<vector<int>> flag(101,vector<int>(101));
    for (int l=0;l<n;l++) {
        cin>>x>>y>>h;
        for (long long int i=0;i<=100;i++) {
            for (long long int j=0;j<=100;j++) {
                if (h==0) {
                    if (vec[i][j].second==0) {
                        vec[i][j]=make_pair(abs(x-i)+abs(y-j),1);
                        flag[i][j]=1;
                    } else if (vec[i][j].first>abs(x-i)+abs(y-j)) {
                        if (flag[i][j]==1) {
                            vec[i][j].first=abs(x-i)+abs(y-j);
                            vec[i][j].second++;
                            if (vec[i][j].second==n) {
                                cout<<i<<" "<<j<<" "<<vec[i][j].first<<endl;
                                return 0;
                            }
                        }
                    } else if (vec[i][j].first<=abs(x-i)+abs(y-j)) {
                        vec[i][j].second++;
                        if (vec[i][j].second==n) {
                            cout<<i<<" "<<j<<" "<<vec[i][j].first<<endl;
                            return 0;
                        }
                    }
                } else {
                    long long int H=h+abs(x-i)+abs(y-j);
                    if (vec[i][j].second==0) {
                        vec[i][j]=make_pair(H,1);
                    } else if (vec[i][j].first==H) {
                        flag[i][j]=0;
                        vec[i][j].second++;
                        if (vec[i][j].second==n) {
                            cout<<i<<" "<<j<<" "<<vec[i][j].first<<endl;
                            return 0;
                        }
                    } else if (flag[i][j]==1&&H<=vec[i][j].first) {
                        vec[i][j].first=H;
                        flag[i][j]=0;
                        vec[i][j].second++;
                        if (vec[i][j].second==n) {
                            cout<<i<<" "<<j<<" "<<vec[i][j].first<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}