#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<char> > vvc;

void paint_for_white(vvc &HW, int A);
void paint_for_black(vvc &HW, int A, int B);
void print_ans(vvc &HW);

void paint_for_firstline(vvc &HW, int A);
void paint_for_middleline(vvc &HW, int A, int cnt);
void paint_black_firstline(vvc &HW, int now_B);
void paint_black_middleline(vvc &HW, int now_B, int cnt);

int main(){
	int A, B;
	cin >> A >> B;
	vvc HW(100, vector<char>(100));
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			HW.at(i).at(j) = '.';
		}
	}
	paint_for_white(HW, A);
	paint_for_black(HW, A, B);
	print_ans(HW);
}

/*++++++++++ function ++++++++++*/
void paint_for_white(vvc &HW, int A){
	bool is_first = true;
	int cnt = 0;

	A -= 1;
	while (A > 0){
		if (is_first){
			paint_for_firstline(HW, A);
			is_first = false;
		}
		else{
			paint_for_middleline(HW, A, cnt);
			cnt++;
		}
		A -= 24;
	}
}

void paint_for_black(vvc &HW, int A, int B){
	int now_B = B - (A - 1);
	// cout << now_B << endl;
	if (now_B > 0){
		int row = 99;
		int column = 0;
		while (now_B){
			// cout << "check " << now_B << endl;
			HW.at(row).at(column) = '#';
			column += 2;
			if (column >= 100){
				row -= 2;
				column = 0;
			}
			now_B--;
		}
	}else if (now_B < 0){
		bool is_first = true;
		int cnt = 0;
		while (now_B < 0){
			if (is_first){
				paint_black_firstline(HW, now_B);
				is_first = false;
				now_B += 23;
			}else{
				paint_black_middleline(HW, now_B, cnt);
				cnt++;
				now_B += 24;
			}
		}
	}
}

void print_ans(vvc &HW){
	cout << 100 << " " << 100 << endl;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			cout << HW.at(i).at(j);
		}
		cout << endl;
	}
}

/*++++++++++ sub function ++++++++++*/
void paint_for_firstline(vvc &HW, int A){
	int paint_num = min(A, 24);
	int cnt = 1;

	HW.at(0).at(1) = '#', HW.at(1).at(0) = '#', HW.at(1).at(1) = '#';
	int paint_pos = 3;
	while (cnt != paint_num){
		HW.at(0).at(paint_pos) = '#', HW.at(0).at(paint_pos + 2) = '#';
		HW.at(1).at(paint_pos) = '#', HW.at(1).at(paint_pos + 1) = '#', HW.at(1).at(paint_pos + 2) = '#';
		cnt++;
		paint_pos += 4;
	}
}

void paint_for_middleline(vvc &HW, int A, int row){
	int paint_num = min(A, 24);
	int paint_pos_1 = 3 + 4*row, paint_pos_2 = 3;
	int cnt = 1;

	HW.at(paint_pos_1).at(0) = '#', HW.at(paint_pos_1 + 2).at(0) = '#';
	HW.at(paint_pos_1).at(1) = '#', HW.at(paint_pos_1 + 1).at(1) = '#', HW.at(paint_pos_1 + 2).at(1) = '#';
	while (cnt != paint_num){
		HW.at(paint_pos_1).at(paint_pos_2) = '#', HW.at(paint_pos_1).at(paint_pos_2 + 1) = '#', HW.at(paint_pos_1).at(paint_pos_2 + 2) = '#';
		HW.at(paint_pos_1 + 1).at(paint_pos_2) = '#', HW.at(paint_pos_1 + 1).at(paint_pos_2 + 2) = '#';
		HW.at(paint_pos_1 + 2).at(paint_pos_2) = '#', HW.at(paint_pos_1 + 2).at(paint_pos_2 + 1) = '#', HW.at(paint_pos_1 + 2).at(paint_pos_2 + 2) = '#';
		cnt++;
		paint_pos_2 += 4;
	}
}

void paint_black_firstline(vvc &HW, int now_B){
	for (int i = 0; i < min(-now_B, 23); i++){
		HW.at(0).at(2 + i*4) = '#', HW.at(1).at(2 + i*4) = '#';
	}
}

void paint_black_middleline(vvc &HW, int now_B, int row){
	int paint_num = min(-now_B, 24);
	// cout << paint_num << endl;

	HW.at(2 + row*4).at(0) = '#', HW.at(2 + row*4).at(1) = '#', HW.at(2 + row*4).at(2) = '#';
	for (int i = 0; i < paint_num - 1; i++){
		if (i == 0) HW.at(3 + row*4).at(2) = '#', HW.at(4 + row*4).at(2) = '#', HW.at(5 + row*4).at(2) = '#';
		else{
			HW.at(2 + row*4).at(4*i - 1) = '#', HW.at(2 + row*4).at(4*i) = '#', HW.at(2 + row*4).at(4*i + 1) = '#', HW.at(2 + row*4).at(4*i + 2) = '#';
			HW.at(3 + row*4).at(4*i + 2) = '#', HW.at(4 + row*4).at(4*i + 2) = '#', HW.at(5 + row*4).at(4*i + 2) = '#';
		}
	}
}
