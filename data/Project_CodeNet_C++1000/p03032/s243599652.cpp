#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,K,ans=0;
    cin >> N >> K;
    vector<long long int> V(N);
    for(int i=0;i<N;i++){
        cin >> V[i];
    }

    for(long long int i=0;i<K;i++){
        vector<long long int> left;
        long long int L=0,in = 0;

        in = min(N,i+1);

        for(int j=0;j<in;j++){
            left.push_back(V[j]);
            L += V[j];
        }

        sort(left.begin(),left.end());

        for(long long int j=0;j<min((long long int)left.size(),(K-in));j++){
            if(left[j]<0){
                L -= left[j];
            }else{
                break;
            }
        }
        ans = max(ans,L);
    }

    for(long long int i=0;i<K;i++){
        vector<long long int> right;
        long long int R=0,in=0;

        in = min(N,i+1);

        for(int j=0;j<in;j++){
            right.push_back(V[N-1-j]);
            R += V[N-1-j];
        }

        sort(right.begin(),right.end());

        for(long long int j=0;j<min((long long int)right.size(),(K-in));j++){
            if(right[j]<0){
                R -= right[j];
            }else{
                break;
            }
        }

        ans = max(ans,R);
    }

    for(long long int i=1;i<K;i++){
        long long int in=0;

        in = min(N,i+1);

        for(long long int j=1;j<in;j++){
            vector<long long int> both;
            long long int LR=0;

            for(long long int k=0;k<j;k++){
                both.push_back(V[k]);
                LR += V[k];
            }

            for(long long int k=0;k<in-j;k++){
                both.push_back(V[N-1-k]);
                LR += V[N-1-k];
            }

            sort(both.begin(),both.end());

            for(long long int k=0;k<min((long long int)both.size(),(K-in));k++){
                if(both[k]<0){
                    LR -= both[k];
                }else{
                    break;
                }
            }
            ans = max(LR,ans);
        }

    }
    cout << ans << endl;
}