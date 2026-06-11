#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
        int d,g, ans=1000;
        cin >> d >> g;
        vector<pair<int,int> > score(d);
        vector<int> scoreSum(d);
        for(int i=0; i<d; i++) {
                cin >> score[i].first >> score[i].second;
                scoreSum[i]=score[i].first*(i+1)*100+score[i].second;
        }
        // d種類の問題について、完全に解くか解かないかを全探索
        for(int i=0; i<pow(2,d); i++) {
                bitset<10> isComplete(i);
                int hardest=d;
                int solved=0;
                int myScore = 0;
                for(int j=d-1; j>=0; j--) {
                        if(isComplete.test(j)) {
                                myScore+=scoreSum[j];
                                solved+=score[j].first;
                                if(hardest==j+1) hardest--;
                        }
                }
                // 現時点でのスコアが目標値以下ならば、どれか1種を中途半端に解けば良い
                if(myScore>=g) ans=min(ans,solved);
                else
                if(myScore<g) {
                        int numNotComplete = (int)(g-myScore+(hardest*100-1))/(hardest*100);
                        if(numNotComplete<score[hardest-1].first) {
                                solved+=numNotComplete;
                                ans=min(ans,solved);
                        }
                }
        }
        cout << ans << endl;
}
