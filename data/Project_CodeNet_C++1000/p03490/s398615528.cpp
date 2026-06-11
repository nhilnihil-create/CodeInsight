#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int line_size = 16001;
const int line_base = line_size / 2;

using namespace std;

bool check_x(vector<int>& str, int answer);
bool check_y(vector<int>& str, int answer);
bool check_func(vector<int>& str, int deep, int answer);

int* line1 = new int[line_size];
int* line2 = new int[line_size];
int* tmp;

int main()
{
	int x = 0, y = 0;
	vector<int> lines;
	int count = 1;
	string code;
	
	cin >> code;
	cin >> x >> y;
	std::string::size_type first, last;

	first = 0;
	last = 0;
	while (last != std::string::npos)
	{
		last = code.find('T', first);
		if (first == last)
		{
			lines.push_back(0);
			first = last + 1;
			continue;
		}
		lines.push_back(code.substr(first, last - first).size());
		first = last + 1;
	}
	/*
	while (count < lines.size())
	{
		switch (count % 2)
		{
		case 0:
			forword_some(lines, lines[count], x);
			break;
		case 1:
			forword_some(lines, lines[count], y);
			break;
		}
		++count;
	}
	*/

	if (check_x(lines, x) == true)
	{
		if (check_y(lines, y) == true)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	else
	{
		cout << "No" << endl;
	}

	delete[] line1;
	delete[] line2;

	return 0;
}

bool check_x(vector<int>& str, int answer)
{
	if (str.size() < 1 && answer == 0)
	{
		return true;
	}
	for (int i = 0; i < line_size; ++i)
	{
		line1[i] = -1;
		line2[i] = -1;
	}
	line1[line_base + str[0]] = 0;
	return check_func(str, 2, answer);
}

bool check_y(vector<int>& str, int answer)
{
	if (str.size() < 2 && answer == 0)
	{
		return true;
	}
	for (int i = 0; i < line_size; ++i)
	{
		line1[i] = -1;
		line2[i] = -1;
	}
	line1[line_base + str[1]] = 0;
	line1[line_base - str[1]] = 0;
	return check_func(str, 3, answer);
}

bool check_func(vector<int>& str, int init_deep, int answer)
{
	bool correct = false;
	int count = 1;
	for (; init_deep < str.size(); init_deep += 2)
	{
		for (int i = 0; i < line_size; ++i)
		{
			if (line1[i] != count - 1)
			{
				continue;
			}

			if (i + str[init_deep] < line_size)
			{
				line2[i + str[init_deep]] = count;
			}
			if (i - str[init_deep] > 0)
			{
				line2[i - str[init_deep]] = count;
			}
		}
		tmp = line1;
		line1 = line2;
		line2 = tmp;
		++count;
	}

	if (line1[line_base + answer] == (count - 1))
	{
		correct = true;
	}

	return correct;
}