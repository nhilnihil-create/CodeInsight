#include<iostream>
using namespace std;
int main()
{
	// 整数の入力
    string input;
    cin >> input;
 
    string first = input.substr(0,2);
    string second = input.substr(2,2); 
    
    int first_num = atoi(first.c_str());
    int second_num = atoi(second.c_str());
    
    bool first_MM = true;
    bool second_MM = true;
  
    if(first_num > 12 || first_num < 1)
    {
        first_MM = false;
    }
    if(second_num > 12 || second_num < 1)
    {
        second_MM = false;
    }
    
    if(first_MM && second_MM)
    {
        // どちらもOK
        cout << "AMBIGUOUS";
    }
    else if(first_MM)
    {
        // MMYY フォーマットのみ
        cout << "MMYY";
    }
    else if(second_MM)
    {
        // YYMM フォーマットのみ
        cout << "YYMM";
    }
    else
    {
        // どちらもだめ   
        cout << "NA";
    }
    
    return 0;
}