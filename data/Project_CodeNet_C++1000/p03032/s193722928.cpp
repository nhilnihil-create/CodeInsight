#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    for(int i=0;i<N;i++){
        cin >> V[i];
    }

    vector<priority_queue<int>> qL(N+1);
    vector<priority_queue<int>> qR(N+1);
    vector<int> sumL(N+1);
    vector<int> sumR(N+1);
    for(int i=0;i<=N;i++){
        for(int j=0;j<i;j++){
            qL[i].push(-V[j]);
            qR[i].push(-V[N-1-j]);
        }
        if(i==N) break;
        sumL[i+1] = sumL[i] + V[i];
        sumR[i+1] = sumR[i] + V[N-1-i];
    }
    auto res = numeric_limits<int>::min();
    for(int il=0;il<=N;il++){
        for(int ir=0;ir<=N;ir++){
            if(il + ir > N) continue;
            auto k = K - il - ir;
            if(k<0) continue;
            int vsum = 0;
            vsum += sumL[il];
            vsum += sumR[ir];
            auto qLt = qL[il];
            auto qRt = qR[ir];
            while(k>0){
                auto v1 = qLt.size()==0? 0 : qLt.top();
                auto v2 = qRt.size()==0? 0 : qRt.top();
                if(v1 <= 0 && v2 <= 0) break;
                else if(v2 <= 0){ vsum += v1; qLt.pop();}
                else if(v1 <= 0){ vsum += v2; qRt.pop();}
                else if(v1 > v2){ vsum += v1; qLt.pop();}
                else            { vsum += v2; qRt.pop();}
                k--;
            }

            res = max(res, vsum);
        }
    }
    cout<<res<<endl;

    return 0;
}