 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;

int main() {
   int d,g;
   cin >> d >> g;
   vector<int> p(d);
   vector<int> c(d);
   for(int i=0;i<d;i++){
       cin >> p[i] >> c[i];
   }
   int nin = 1e9;
    //----- bit 全探索 ------
    //ここで2^d-1個のbit列を列挙
    for (int bit = 0; bit < (1 << d); ++bit) {
        int score=0;
        int solve=0;
        //配列のコピー
        vector<int> copy_p = p;
        //ここで、列の各位が1かをみる
        for (int i = 0; i < d; ++i) {
            if (bit & (1 << i)) {
            // 1のところのボーナスポイントを取る
                copy_p[i] = 0;
                solve+=p[i];
                score+=p[i]*100*(i+1);
                score+=c[i];
            }
        }
        if(score>=g){
            nin = min(nin,solve);
        }
        else{
            for(int i=d-1;i>=0;i--){
                // 既に選んでいればbreak;
                while(copy_p[i]>0){
                    if(score>=g) {
                        nin = min(nin,solve);
                        break;
                    }
                    solve++;
                    score+=(i+1)*100;
                    copy_p[i]--;
                    if(copy_p[i]==0) score+=c[i];
                }
                if(score>=g) break;
            }
        }
        
    }
    cout << nin << endl;
}