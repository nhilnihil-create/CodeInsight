#include<bits/stdc++.h>
using namespace std;
int pow4(int n){
    int ans = 1;
    for(int i=0;i<n;i++)ans*=4;
    return ans;
}

int main(){
    int n;
    int nagasa[3];
    cin >> n >> nagasa[0]>>nagasa[1]>>nagasa[2];
    int l[n];
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    int minMp = 1<<30;
    for(int bit = 0;bit<(1<<(2*n));bit++){
        vector<vector<int> >take(3);
        for(int i=0;i<n;i++){
            int num = (bit / pow4(i))%4;
            if(num != 3){
                take[num].push_back(l[i]);
            }
        }
        bool chkk = false;
        for(int i=0;i<3;i++){
            if(take[i].size() == 0)chkk = true;
        }
        if(chkk)continue;

        int mp = 0;
        
        for(int i=0;i<3;i++){
            mp += 10*(take[i].size()-1);
            int summ = 0;
            for(int j=0;j<take[i].size();j++){
                summ += take[i][j];
            }
            mp += abs(summ - nagasa[i]);
            
        }
        minMp = min(minMp,mp);

        
    }
    cout << minMp<<endl;
}