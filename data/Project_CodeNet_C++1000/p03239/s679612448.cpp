#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, T;
	int aux1, aux2, aux3,indice, menor = 1001;
	cin >> N;
	cin >> T;
	bool valided= true;
	vector<pair<int, int>>number;
	for (int i = 0; i < N; i++) {
		pair<int, int>aux;
		cin >> aux1;
		cin >> aux2;
		aux.first = aux1;
		aux.second = aux2;
		number.push_back(aux);
	}
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < number.size(); k++) {
			if (number[k].first < menor) {
				aux3 = number[k].first;
				menor = aux3;
				indice = k;
			}
		}
		if (number[indice].second <= T){
			valided = false;
			break;
	}
		else number.erase(number.begin() + indice);
		menor = 1001;
	}
	if (valided == false)
		cout << number[indice].first << endl;
	else
		cout << "TLE" << endl;
	return(0);
}