#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //input
    int N,M;
    cin >> N >>M;
    int i,j;
    vector<pair<int,int> > start, goal;
    int a,b;
    for(i=0; i<M; i++){
        cin >> a  >> b;
        start.push_back(make_pair(a-1,i));
        goal.push_back(make_pair(b-1,i));
    }

    //calc
    sort(start.begin(),start.end());
    sort(goal.begin(),goal.end());
    bool usable[M];
    fill(usable,usable+M,1);
    int ans=0, j_sta=0;
    for(i=0; i<M; i++){
        if(usable[goal[i].second]){
            ans++;
            usable[goal[i].second]=0;
            for(j=j_sta; j<M; j++){
                if(start[j].first<goal[i].first){
                    usable[start[j].second]=0;
                }else{
                    break;
                }
            }
            j_sta=j;
        }
    }

    //answer
    cout << ans << endl;
    system("pause");
    return 0;
}