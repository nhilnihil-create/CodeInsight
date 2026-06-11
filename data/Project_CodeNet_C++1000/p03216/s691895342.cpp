#include <iostream>
#include <vector>

using namespace std;

int cumsum_m[1000000];
vector<int> c_idx, d_idx;

long count_k(int l, int r){
    return cumsum_m[r]-cumsum_m[l];
}

int main(){
    int N;
    string S;
    int Q;
    cin >> N;
    cin >> S;
    cin >> Q;
    int cnt = 0;
    c_idx.push_back(-1);
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'M') cnt++;
        if(S[i] == 'D') d_idx.push_back(i);
        if(S[i] == 'C') c_idx.push_back(i);
        cumsum_m[i] = cnt;
    }
    for(int i = 0; i < Q; i++){
        int k;
        cin >> k;
        int cl = 0, cr  = 0;
        long tmp = 0;
        long ans = 0;
        while(cl+1 < c_idx.size() && c_idx[cl] < d_idx[0]){
            cl++;
        }
        while(cr+1 < c_idx.size() && c_idx[cr+1] < d_idx[0]+k){
            cr++;
        }
        if(c_idx[cl] > d_idx[0] && c_idx[cr] < d_idx[0]+k){
            for(int j = cl; j <= cr; j++){
                tmp += count_k(d_idx[0], c_idx[j]);
            }
        }
        ans += tmp;
        //cout << ans << ' ' << cl << ' ' << cr << endl;
        for(int j = 1; j < d_idx.size(); j++){
            int diff = cr-cl+1;
            int cnt_dec = 0;
            int prev_cl = cl;
            while(cl+1 < c_idx.size() && c_idx[cl] < d_idx[j]){
                if(c_idx[cl] > d_idx[j-1]) tmp -= count_k(d_idx[j-1], c_idx[cl]);
                cl++;
                cnt_dec++;
            }
            //cout << tmp << endl;
            if(c_idx[prev_cl] > d_idx[j-1]) tmp -= max(diff-cnt_dec, 0)*count_k(d_idx[j-1] , d_idx[j]);
            //cout << tmp << endl;
            while(cr+1 < c_idx.size() && c_idx[cr+1] < d_idx[j]+k){
                cr++;
                if(c_idx[cr] > d_idx[j]) tmp += count_k(d_idx[j], c_idx[cr]);
            }
            if(c_idx[cl] > d_idx[j] && c_idx[cr] < d_idx[j]+k) ans += tmp;
            else tmp = 0;
            //cout << ans << ' ' << tmp << ' ' << cl << ' ' << cr << endl;
        }
        cout << ans << endl;
    }
}