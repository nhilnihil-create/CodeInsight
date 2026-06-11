#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    int a;
    //Restaurantというペア型（string,int）の配列を用意して
    //入力の値（市の名前 , 点数）を順番にRestaurant配列へ登録していく
	vector<pair<string , int>> Restaurant;
    for(int i = 0; i < N; i++){
        cin >> s >> a;
    	Restaurant.push_back(make_pair(s, a));
    }
    pair<string , int> temp; //Restaurant配列の中身を一時的に保存するためのペア型の変数
    int count; //N個のレストランの中の何番目なのかを表す変数
    vector<int> Result(N); //入力の値（市の名前 , 点数）が何番目なのかを記録するための配列
    for(int i = 0; i < N; i++){
        count = 1;
    	temp = Restaurant.at(i);
        for(int j = 0; j < N; j++){
            //それぞれの市の名前を比較して、tempの市名がRestaurant.at(i)の市名より、辞書順で後だったらcountを1増やす
        	if(temp.first > Restaurant.at(j).first ){
            	count++;
            }
            //もしtempの市名とRestaurant.at(i)の市名が同じだった場合に、
            //tempの点数がRestaurant.at(i)の点数より低かったらcountを1増やす
            else if(temp.first == Restaurant.at(j).first){
            	if(temp.second < Restaurant.at(j).second){
                	count++;
                }
            }
        }
        //入力の値（市の名前 , 点数）が何番目なのかを記録する
        Result.at(i) = count;
    }
    //入力の値（市の名前 , 点数）の中で順位の早いものから[要素番号 + 1] の値を出力していく
    for(int i = 0; i < N ; i++){
    	for(int j = 0; j < N; j++){
        	if(Result.at(j) == i + 1){
            	cout << j + 1 << endl;
            }
        }
    }
}