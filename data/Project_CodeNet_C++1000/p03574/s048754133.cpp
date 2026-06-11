#include <iostream>
//#include <vector>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	char boxs[60][60] = {0}; //2次元表の作成・初期値に0を入力
	//追記:vectorなら  vector <vector <char>> boxs(60,vector <char>(60,0));
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> boxs[i][j];						//表に値を代入
		}
	}
	for (int i = 0; i < x; i++) {					//縦
		for (int j = 0; j < y; j++) {				//横
			if (boxs[i][j] == '#') {
				cout << '#';						//配列の中身が#ならばそのまま#を入力し無視する。
			}
			else if(boxs[i][j] =='.'){				//空きマスかを確認（初期値を0としているため）
				int add=0;							//ボムの量をカウントするカウンターの作成
													//存在するなら値を１プラスする
				if (i != 0 && j != 0) {				//左上に配列が存在するならば左上が#か確認
					if (boxs[i - 1][j - 1] == '#') {
						add++;
					}
				}
				if (i != 0) {						//上に配列が存在するなら
					if (boxs[i - 1][j + 1] == '#') {//右上を確認
						add++;
					}
					if (boxs[i - 1][j] == '#') {	//上を確認
						add++;
					}
				}
				if (j !=0) {						//左が存在するならば
					if (boxs[i][j - 1]=='#') {		//左を確認
						add++;
					}
					if (boxs[i + 1][j - 1] == '#') {//左下を確認
						add++;
					}
				}
				if (boxs[i][j + 1] == '#') {		//右を確認
					add++;
				}
				if (boxs[i + 1][j] == '#') {		//下を確認
					add++;
				}
				if (boxs[i + 1][j+1] == '#') {		//右下を確認
					add++;
				}
				cout << add;						//値を出力
			}
		}
		cout << endl;								//改行を入力
	}
}