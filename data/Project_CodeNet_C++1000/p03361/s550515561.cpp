#include <iostream>
#include <vector>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;


namespace IO {
    template <typename TYPE>
        class TableIO {
            public:
                // 標準入力から二次元配列を作成
                static vector<vector<TYPE> > MakeTable(); // 標準
                static vector<vector<TYPE> > MakeTableWithWall(const TYPE& init); // 壁付き
                // 二次元配列を出力
                static void PrintTable(const vector<vector<TYPE> >& table); 
        };

    // 標準入力から二次元配列を作成
    template <typename TYPE>
        vector<vector<TYPE> > TableIO<TYPE>::MakeTable() {
            Int h, w;
            cin >> h >> w;
            vector<vector<TYPE> > input(h, vector<TYPE>(w));
            for (Int i = 0; i < h; ++i) {
                for (Int j = 0; j < w; ++j) {
                    cin >> input[i][j];
                }
            }
            return input;
        }
    // 標準入力から二次元配列を作成
    template <typename TYPE>
        vector<vector<TYPE> > TableIO<TYPE>::MakeTableWithWall(const TYPE& init) {
            Int h, w;
            cin >> h >> w;
            vector<vector<TYPE> > input(h + 2, vector<TYPE>(w + 2, init));
            for (Int i = 1; i <= h; ++i) {
                for (Int j = 1; j <= w; ++j) {
                    cin >> input[i][j];
                }
            }
            return input;
        }

    // 二次元配列を出力
    template <typename TYPE>
        void TableIO<TYPE>::PrintTable(const vector<vector<TYPE> >& table) {
            for (Int i = 0; i < table.size(); ++i) {
                for (Int j = 0; j < table[0].size(); ++j) {
                    cout << table[i][j] << " ";
                }
                cout << endl;
            }
            return;
        }
}
using namespace IO;

bool tonari(vector<vector<char> >& v, Int i, Int j) {
    if (v[i - 1][j] == '#') {
    } else if (v[i + 1][j] == '#') {
    } else if (v[i][j - 1] == '#') {
    } else if (v[i][j + 1] == '#') {
    } else {
        return false;
    }
    return true;
}

int main(void) {
    vector<vector<char> > v = TableIO<char>::MakeTableWithWall('.');
    //TableIO<char>::PrintTable(v);
    bool result = true;
    for (Int i = 1; i < v.size(); ++i) {
        for (Int j = 1; j < v[0].size(); ++j) {
            if (v[i][j] == '.') {
            } else if (v[i][j] == '#' && tonari(v, i, j)) {
            } else {
                result = false;
            }
        }
    }
    if (result == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

