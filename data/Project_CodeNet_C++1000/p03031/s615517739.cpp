#include <iostream>
#include <map>
#include <vector>
#include <bitset>
using namespace std;

int main() {

    int N; // スイッチ（on / off）
    int M; // 電球 -> K個のスイッチ

    cin >> N >> M ;

    // M 行,  - 列
    vector<vector<int>> data(M, vector<int>());

    // 電球個数ループ
    for (int i = 0; i < M; i++) {

        // スイッチ個数
        int K;
        cin >> K;

        data[i].push_back(K);

        // スイッチ個数ループ
        int k[K];
        for (int j = 0; j < K; j++) {
            cin >> k[j];
            data[i].push_back(k[j]);
        }
    }

    // 電球個数ループ
    int p[M];
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }

    int cnt = 0;

    // N個のスイッチの、ON/OFF 全組み合わせループ
    for (int tmp = 0; tmp < (1 << N); tmp++) {
        //ビット表現(0000)
        bitset<10> s(tmp);
        //cout << "---------" << s << "---------" << endl;

        int m_on[M];

        // 電球個数ループ
        for (int i = 0; i < M; i++) {

            int ken = data[i][0];
            //cout << (i+1) << " 件目電球:スイッチ " << ken << "個 ループ開始"<<endl;
            int on = 0;

            // スイッチ個数ループ
            for (int j = 1; j <= ken; j++) {
                //cout << "スイッチ番号 :" << data[i][j] << endl;

                //　k[j] ビット目のビット有り
                if (s.test(data[i][j]-1)) {
                    //cout << "スイッチ番号 :" << data[i][j] << " on "<<endl;
                    on++;
                }
            }


            //cout << (i+1) << " 件目:スイッチ " << "on件数 " << on << endl;
            //cout << "P " << p[i] << endl;
            if (p[i] == on % 2){
                m_on[i] = 1;
                //cout << (i+1) << "件目電球 - ON" << endl;
            }
            else{
                //cout << (i+1) << "件目電球 - OFF" << endl;
                m_on[i] = 0;
            
            }
        }
        bool flg = true;
        for (int i = 0; i < M; i++) {
            if (m_on[i] == 0){
                flg = false;
            }
        }
        if(flg){
            //cout << "-----------cnt up" << endl;
            cnt++;
        }
    }

    cout << cnt << endl;


    return 0;

}